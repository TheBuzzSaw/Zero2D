#include "NetworkStream.h"
#include "Exception.h"
#include <sstream>

namespace CGE
{
    NetworkStream::NetworkStream(size_t inSize)
        : mSize(inSize)
    {
        mPacket = SDLNet_AllocPacket(mSize);
    }

    NetworkStream::~NetworkStream()
    {
        SDLNet_FreePacket(mPacket);
    }

    void NetworkStream::openSocket(Uint16 inPort)
    {
        static const char* functionName = "NetworkStream::openSocket";

        if (mSocket)
        {
            throw Exception(functionName, "socket already open");
        }
        else
        {
            mSocket = SDLNet_UDP_Open(inPort);

            if (!mSocket)
                throw Exception(functionName, "failed to open socket");
        }
    }

    void NetworkStream::connect(const char* inAddress, Uint16 inPort)
    {
        static const char* functionName = "NetworkStream::connect";

        if (SDLNet_ResolveHost(&mAddress, inAddress, inPort) == -1)
        {
            std::ostringstream oss;
            oss << "failed to resolve host -- " << inAddress << " on port "
                << inPort;
            throw Exception(functionName, oss.str());
        }
    }

    void NetworkStream::sendData(const void* inData, size_t inLength)
    {
        static const char* functionName = "NetworkStream::sendData";

        if (inLength > mSize)
            throw Exception(functionName, "data too large to transmit");

        memcpy(mPacket->data, inData, inLength);
        mPacket->len = inLength;
        mPacket->address.host = mAddress.host;
        mPacket->address.port = mAddress.port;
        SDLNet_UDP_Send(mSocket, -1, mPacket);
    }

    bool NetworkStream::receiveData(Uint8* inCapture)
    {
        if (SDLNet_UDP_Recv(mSocket, mPacket))
        {
            memcpy(inCapture, mPacket->data, mPacket->len);
            //cerr << "mPacket->address/port: " << mPacket->address.host << ", "
            //    << SDL_Swap16(mPacket->address.port) << endl;
            return true;
        }

        return false;
    }
}
