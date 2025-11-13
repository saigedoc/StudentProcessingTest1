#include <iostream>
#include <zmq.hpp>

int main() {
    zmq::context_t ctx;
    zmq::socket_t client(ctx, ZMQ_REQ);
    client.connect("tcp://localhost:88888");
    printf("Sending request...\n");
    zmq::message_t request;
    client.send(request);

    printf("Waiting responce...\n");
    zmq::message_t responce;
    client.recv(responce);

    std::vector<std::string> students_data;
    const char* p = static_cast<const char*>(responce.data());
    const char* end = p + responce.size();

    while (p < end) {
        const char* start = p;
        while (p < end && *p != '\0') ++p;
        if (start == p) break;
        students_data.emplace_back(start, p - start);
        ++p;
    }

    printf("Got server responce, goten list of students:\n\n");
    for (int i = 0; i < students_data.size(); ++i){
        printf("%s\n", students_data[i].c_str());
    }
    std::cin.get();
    return 0;
}