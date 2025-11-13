#include <iostream>
#include "student_data.h"
#include <zmq.hpp>

int main() {
    try {
        zmq::context_t ctx;
        zmq::socket_t server(ctx, ZMQ_REP);
        server.bind("tcp://localhost:88888");
        printf("Wait for request...\n");
        zmq::message_t request;
        server.recv(request);
        printf("Got request, processing data...\n");
        ProcessData pd("student_file_1.txt", "student_file_2.txt");
        std::vector<std::string> students_data = pd.get_data();
        printf("Processed list of students:\n\n");
        std::string buffer;
        for (int i = 0; i < students_data.size(); ++i){
            buffer += students_data[i].c_str();
            buffer += '\0';
            printf("%s\n", students_data[i].c_str());
        }
        zmq::message_t response(buffer.size());
        memcpy(response.data(), buffer.data(), buffer.size());

        server.send(response);
        printf("Processed list send.\n");
        std::cin.get();
        return 0;
    } 
    catch (const std::exception& e) {
        fprintf(stderr, "\nEXCEPTION: %s\n", e.what());
        std::cin.get();
        return 0;
    } 
}