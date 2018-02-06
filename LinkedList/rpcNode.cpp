#include "stdafx.h"
#include "rpcNode.h"


rpcNode::rpcNode()
{
	m_iData = 0;
	m_pLast = m_pNext = nullptr;
}

rpcNode::rpcNode(int iData) : rpcNode()
{
	m_iData = iData;
}

int rpcNode::compareTo(rpcNode* pNode)
{
	if (!pNode || m_iData > pNode->m_iData) return 1;
	if (m_iData == pNode->m_iData) return 0;
	return -1;
}

std::string rpcNode::toString()
{
	std::stringstream ss;
	ss << "{Data: " << m_iData << "}";
	return ss.str();
}

rpcNode::~rpcNode()
{
	if (m_pLast) m_pLast->m_pNext = m_pNext;
	if (m_pNext) m_pNext->m_pLast = m_pLast;
}
