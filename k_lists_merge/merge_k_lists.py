# This is an implementation of k-sorted lists merge 
from typing import List


def merge(l_1: List[int] , l_2 : List[int]) -> List[int] :
    res = []
    while (l_1 and l_2):
        res.append(l_1.pop(0) if (l_1[0] <= l_2[0]) else l_2.pop(0))
    res.extend(l_1 if l_1 else l_2)
    return res


# First obvious way is to loop throw lists and merge each one of i'th index with the i+1'th list
# and this is using the axialary function merge(l_1,l_2) 
# This way we will get an O(nlog(n)) complexity 
def merge_k_lists(lists : List[List[int]]) -> List[int] :
    
    if not lists : return None

    while len(lists) > 1:
        merged=[]
        for i in range(0,len(lists),2):
            l_1 = lists[i]
            l_2 = lists[i+1] if (i+1) < len(lists) else None
            merged.append(merge(l_1,l_2))
        lists = merged
    return lists[0]

# TODO -- 
# using a min_heap in O(n) time and O(1) space


# TODO --
# Turn it to O(n) or O(nlog(n)) instead of O(n^2)
def sql_sum_gBy(T) :
    return [(x,sum(T[i][2])) for i in range(len(T)) for x in set(map(lambda x:x[0], T)) if x == T[i][2]]


if __name__ == '__main__':
    # print(merge_k_lists([[1,2,3],[2,3,5,6],[3,4,7,9,12]]))
    T = [(3, "h", 8), (3, "i", 7), (5, "p", 10), (7, "l", 2), (7, "hg", 8), (10, "nn", 2) ]
    print(sql_sum_gBy(T))
