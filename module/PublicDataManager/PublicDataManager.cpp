#include "PublicDataManager.h"
#include <algorithm>

std::vector<MyFriendInfoWithFirstC>& PublicDataManager::getMyFriendInfoWithCVec()
{
    return m_vecFriendInfoWithC;
}

std::vector<MyLastChatFriendInfo>& PublicDataManager::getMyLastChatFriendInfoVec()
{
    return m_vecLastChatFriend;
}

std::unordered_map<QString, int>& PublicDataManager::getMyUsetInfoMap()
{
    return m_mapUserInfo;
}

QString PublicDataManager::getMyId() const
{
    return m_strId;
}

QString PublicDataManager::getMyName() const
{
    return m_strName;
}

CurrentChatWidgetUserInfo PublicDataManager::getCurrentChatWidgetUserInfo() const
{
    return m_stuCurrentChatUserInfo;
}

MyFriendInfoWithFirstC PublicDataManager::getFriendInfoAcordId(const QString& id)
{
    return m_vecFriendInfoWithC[m_mapUserInfo[id]];
}

void PublicDataManager::setMyFriendInfoWithC(const std::vector<MyFriendInfoWithFirstC>& vecFriendInfoWithC)
{
    m_vecFriendInfoWithC = vecFriendInfoWithC;
}

void PublicDataManager::setMyLastChatInfo(const std::vector<MyLastChatFriendInfo>& vecLastChatFriend)
{
    m_vecLastChatFriend = vecLastChatFriend;
}

void PublicDataManager::setUserInfo(const std::unordered_map<QString, int>& mapUserInfo)
{
    m_mapUserInfo = mapUserInfo;
}

void PublicDataManager::setMyId(const QString& id)
{
    m_strId = id;
}

void PublicDataManager::setMyName(const QString& name)
{
    m_strName = name;
}

void PublicDataManager::setCurrentChatWidgetUserInfo(const CurrentChatWidgetUserInfo& info)
{
    m_stuCurrentChatUserInfo = info;
}

void PublicDataManager::setUnreadMsg(const QString& id, int cnt)
{
    if (m_mapUnreadMsgCnt.count(id))
    {
        m_mapUnreadMsgCnt[id] = 0;
        m_mapUnreadMsgCnt[id] += cnt;
    }
    else
    {
        m_mapUnreadMsgCnt[id] += cnt;
    }
}

void PublicDataManager::clearUnreadMsg(const QString& id)
{
    m_mapUnreadMsgCnt.erase(id);
}

int PublicDataManager::getUnreadMsgCnt(const QString& id) const
{
    return m_mapUnreadMsgCnt.at(id);
}

bool PublicDataManager::isIdExistInLastChatList(const QString& id) const
{
    for (auto& listItem : m_vecLastChatFriend)
    {
        if (listItem.m_strId == id)
        {
            return true;
        }
    }
    return false;
}

void PublicDataManager::insertLastChatList(const MyLastChatFriendInfo& info)
{
    m_vecLastChatFriend.push_back(info);
}
