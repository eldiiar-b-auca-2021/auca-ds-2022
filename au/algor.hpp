#pragma once

#include <utility>

template <typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}
template <typename BiDirectionalIt>
void auReverse(BiDirectionalIt beg, BiDirectionalIt end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }
        end--;
        if (beg == end)
        {
            break;
        }
        auSwap(*beg, *end);
        beg++;
    }
}
template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, Key &key)
{
    for (; beg != end; ++beg)
    {
        if (*beg == key)
        {
            return beg;
        }
    }
    return beg;
}
template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate pred)
{
    for (; beg != end; beg++)
    {
        if (pred(*beg))
        {
            return beg;
        }
    }
    return beg;
}