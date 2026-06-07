#pragma once

#include <deque>
#include <string>

class StreamingIO
{
public:
    struct Request
    {
        std::string cellPath;
        int priority = 0;
    };

    void QueuePrefetch(const std::string& cellPath, int priority);
    bool PopNext(Request& outRequest);
    int PendingCount() const { return static_cast<int>(m_queue.size()); }

private:
    std::deque<Request> m_queue;
};
