//
// Created by 78241 on 10/8/2019.
// 23. 合并K个排序链表

#include "bits/stdc++.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *merge2Lists(ListNode *p, ListNode *q) {
        if(p==NULL)
            return q;
        if(q==NULL)
            return p;

    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return NULL;
        if (lists.size() == 1)
            return lists.front();
        while (lists.size() > 1) {
            ListNode *p = lists.back();
            lists.pop_back();
            ListNode *q = lists.back();
            lists.pop_back();
            lists.push_back(merge2Lists(p,q));
        }
        return lists.front();
    }
};

