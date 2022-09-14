//
// Created by Libin Zhou on 8/10/22.
//

#ifndef NEC_ROADN_ALGORITHMS_QUERYRESULT_H
#define NEC_ROADN_ALGORITHMS_QUERYRESULT_H

#endif //NEC_ROADN_ALGORITHMS_QUERYRESULT_H
#ifndef QUERYResult
#define QUERYResult
struct _SPResult{
    float result;
    int number_of_hops;
};
struct _priority_queue_entry{
    int id;
    float weight;
    int previousID;
    bool operator<(_priority_queue_entry const & rhs) const
    {
        return weight > rhs.weight;
    }
};
typedef _SPResult SPResult;
typedef _priority_queue_entry Entry;
struct CompareWeight{
    bool operator()(Entry const& p1, Entry const& p2) const
    {
        return p1.weight > p2.weight;
    }
};
#endif