#ifndef ADQSEVEN_H
#define ADQSEVEN_H

#include <nds3/nds.h>
#include "ADQInfo.h"
#include "ADQAIChannelGroup.h"

class ADQSeven : public ADQAIChannelGroup
{
public:
    ADQSeven(const std::string& name, nds::Node& parentNode, ADQInterface *& adqDev);
    virtual ~ADQSeven();

    // Pointer to channel group class
    std::vector<std::shared_ptr<ADQAIChannelGroup> > m_AIChannelGroupPtr;

    void setChanActive(const timespec &pTimestamp, const std::int32_t &pValue);
    void getChanActive(timespec* pTimestamp, std::int32_t* pValue);
    void setChanMask(const timespec &pTimestamp, const std::string &pValue);
    void getChanMask(timespec* pTimestamp, std::string* pValue);
    void setTrigChan(const timespec &pTimestamp, const std::int32_t &pValue);
    void getTrigChan(timespec* pTimestamp, std::int32_t* pValue);

    void commitChangesSpec(bool calledFromDaqThread = false);

private:
    nds::Port m_node;
    ADQInterface * m_adqDevPtr;

    nds::PVDelegateIn<std::int32_t> m_chanActivePV;
    nds::PVDelegateIn<std::string> m_chanMaskPV;
    nds::PVDelegateIn<std::int32_t> m_trigChanPV;
};

#endif /* ADQSEVEN_H */