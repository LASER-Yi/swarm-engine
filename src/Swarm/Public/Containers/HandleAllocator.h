#pragma once

#include <queue>

template <typename T = std::size_t>
class THandleAllocator
{
public:
    THandleAllocator() : Next(), Fragment() {}

    T Allocate()
    {
        T Value;
        if (Fragment.empty() == false)
        {
            Value = Fragment.front();
            Fragment.pop();
        }
        else
        {
            Value = Next;
            Next = Next + 1;
        }

        return Value;
    }

    void Release(T InValue) { Fragment.push(InValue); }

    void Reset()
    {
        Next = T();
        while (Fragment.empty() == false)
        {
            Fragment.pop();
        }
    }

private:
    T Next;
    std::queue<T> Fragment;
};
