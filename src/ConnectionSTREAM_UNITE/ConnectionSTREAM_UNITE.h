/**
    @file ConnectionSTREAM_UNITE.h
    @author Lime Microsystems
    @brief Implementation of STREAM+UNITE board combination connection.
*/

#pragma once
#include <ConnectionRegistry.h>
#include <ConnectionHandle.h>
#include <ConnectionEVB7COM/ConnectionEVB7COM.h>
#include <ConnectionSTREAM/ConnectionSTREAM.h>

namespace lime
{
class ConnectionSTREAM_UNITE : public virtual ConnectionSTREAM
{
public:
    ConnectionSTREAM_UNITE(void* ctx, const std::string &vidpid, const std::string &serial, const unsigned index, const char* comPortName=nullptr);
    virtual ~ConnectionSTREAM_UNITE(void);

    virtual DeviceInfo GetDeviceInfo(void) override;
    virtual int TransactSPI(const int addr, const uint32_t *writeData, uint32_t *readData, const size_t size) override;
    virtual int DeviceReset(void) override;
    virtual int TransferPacket(GenericPacket &pkt) override;
protected:
    ConnectionEVB7COM *comPort;
};

class ConnectionSTREAM_UNITEEntry : public virtual ConnectionSTREAMEntry
{
public:
    ConnectionSTREAM_UNITEEntry(void);
    ~ConnectionSTREAM_UNITEEntry(void);
    std::vector<ConnectionHandle> enumerate(const ConnectionHandle& hint);
    IConnection* make(const ConnectionHandle& handle);
};

}
