#include <queue>
#include <mutex>
#include <condition_variable>
#include <type_traits>
#include "waitable_queue.hpp"

namespace advcpp {

template <typename T , typename Q >  
WaitableQueue<T,Q>::WaitableQueue(size_t a_capcity)
: m_queue()
, m_mtx()
, m_capcity(a_capcity)
, m_notFull()
, m_notEmpty()
{
}  

template <typename T , typename Q >  
bool WaitableQueue<T, Q>::empty() const
{
    std::unique_lock<std::mutex> lock(m_mtx);
    return m_queue.empty();
}

template <typename T , typename Q >  
bool WaitableQueue<T, Q>::innerEmpty() const noexcept
{
    return m_queue.empty();
}

template <typename T, typename Q> 
bool WaitableQueue<T, Q>::full() const
{
    std::unique_lock<std::mutex> lock(m_mtx);
    return m_queue.size() == m_capcity;
}

template <typename T , typename Q >  
bool WaitableQueue<T, Q>::innerFull() const noexcept
{
    return m_queue.size() == m_capcity;
}

template <typename T, typename Q> 
size_t WaitableQueue<T, Q>::size() const
{
    std::unique_lock<std::mutex> lock(m_mtx);
    return m_queue.size();
}

template <typename T , typename Q >  
void WaitableQueue<T, Q>::enqueue(T const& a_item)
{
    std::unique_lock<std::mutex> lock(m_mtx);
    while(innerFull()) {
        m_notFull.wait(lock);
    }

    m_queue.push(a_item);
    
    m_notEmpty.notify_all();
}

template <typename T , typename Q >  
void WaitableQueue<T, Q>::dequeue(T& a_item)
{
    std::unique_lock<std::mutex> lock(m_mtx);
    while(innerEmpty()) {
        m_notEmpty.wait(lock);
    }

    if constexpr(std::is_same_v<Q, std::priority_queue<T>>) {
        a_item = m_queue.top();
    }
    else {
        a_item = m_queue.front();
    }
    m_queue.pop();

    m_notFull.notify_all();
}
} // namespace advcpp
