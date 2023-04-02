#include "StartGroupChatJsonData.h"

namespace protocol
{
    StartGroupChatInnerData::StartGroupChatInnerData(const std::string& message)
    {
        parse(message);
    }

    StartGroupChatInnerData::~StartGroupChatInnerData()
    {
    }

    void StartGroupChatInnerData::parse(const std::string& message)
    {
        if (message.empty())
        {
            return;
        }
        ptree m_ptree;
        std::stringstream sstream(message);
        read_json(sstream, m_ptree);
        m_strGroupName = m_ptree.get<std::string>("GroupName");
        m_strGuid = "";
        m_strStarterId = m_ptree.get<std::string>("StartId");
        //��json��������ȡgruopchatid
        for (auto& item : m_ptree.get_child("GroupChatId"))
        {
            m_vecGroupChat.push_back(item.second.get_value<std::string>());
        }
    }

    std::string StartGroupChatInnerData::generateJson()
    {
        ptree m_ptree;
        m_ptree.put("type", static_cast<int>(m_strType));
        m_ptree.put("StarterId", m_strStarterId.c_str());
        m_ptree.put("Guid", m_strGuid.c_str());
        ptree m_ptreeGroupChat;
        for (auto& item : m_vecGroupChat)
        {
            m_ptreeGroupChat.push_back(std::make_pair("", ptree(item)));
        }
        m_ptree.add_child("GroupChatId", m_ptreeGroupChat);

        std::stringstream sstream;
        write_json(sstream, m_ptree);
        return sstream.str();
    }

    StartGroupJsonData::StartGroupJsonData(const std::string& message)
    {
        parse(message);
    }

    StartGroupJsonData::~StartGroupJsonData()
    {
    }

    void StartGroupJsonData::parse(const std::string& message)
    {
        if (message.empty())
        {
            return;
        }
        ptree m_ptree;
        std::stringstream sstream(message);
        read_json(sstream, m_ptree);
        m_iImageLenth = m_ptree.get<int>("ImageLength");
        m_strImageSuffix = m_ptree.get<std::string>("ImageSuffix");
        m_stInnerData.parse(m_ptree.get<std::string>("InnerData"));
    }

    std::string StartGroupJsonData::generateJson()
    {
        ptree m_ptree;
        m_ptree.put("type", static_cast<int>(m_strType));
        m_ptree.put("ImageLength", m_iImageLenth);
        m_ptree.put("ImageSuffix", m_strImageSuffix.c_str());
        m_ptree.put("InnerData", m_stInnerData.generateJson().c_str());
        std::stringstream sstream;
        write_json(sstream, m_ptree);
        return sstream.str();
    }
}