#pragma once

struct KillData;

class KillDataRequester
{
public:

    KillDataRequester(KillDataRequester* parentKDR) : m_parentKDR(parentKDR){}
    virtual ~KillDataRequester() = default;
    
    virtual bool requestKillData(KillData& data)
    {
        if(m_parentKDR)
            return m_parentKDR->requestKillData(data);
        else
            return false;
    }

protected:

    KillDataRequester* m_parentKDR = nullptr;
};
