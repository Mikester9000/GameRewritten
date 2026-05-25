#include "StreamingIO.hpp"

#include <algorithm>

void StreamingIO::QueuePrefetch(const std::string& cellPath, int priority)
{
    if (cellPath.empty())
        return;

    for (const Request& existing : m_queue)
    {
        if (existing.cellPath == cellPath)
            return;
    }

    Request req;
    req.cellPath = cellPath;
    req.priority = priority;

    auto it = m_queue.begin();
    for (; it != m_queue.end(); ++it)
    {
        if (priority > it->priority)
            break;
    }
    m_queue.insert(it, req);
}

bool StreamingIO::PopNext(Request& outRequest)
{
    if (m_queue.empty())
        return false;

    outRequest = m_queue.front();
    m_queue.pop_front();
    return true;
}
