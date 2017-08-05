#include "../src/cvec.h"

int main (){

    struct vcLog *vcInfo = initCVector("MyProcess","basiclog");
    //Prepare  and send a Message
    int size;
    char sendingMessage[50];
    strcpy(sendingMessage, "ExampleMessage");
    printf("We are packing this message: %s\n", sendingMessage);
    char * resultBuffer = prepareSend(vcInfo, "Sending Message", sendingMessage, 50, &size);
    //Unpack the message again
    char * receivedMessage = unpackReceive(vcInfo, "Receiving Message", resultBuffer, size);
    printf("We received this message: %s\n", receivedMessage);

    //Can be called at any point 
    logLocalEvent(vcInfo, "Example Complete");
    //No further events will be written to log file
    disableLogging(vcInfo);
    logLocalEvent(vcInfo, "This will not be logged.");
}