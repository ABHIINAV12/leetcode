/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vt; while(l1!=nullptr){
            vt.push_back(l1->val);
            l1=l1->next;
        }
        vector<int> wt; while(l2!=nullptr){
            wt.push_back(l2->val);
            l2=l2->next;
        }
        int n=vt.size(),m=wt.size();
        int diff=abs(n-m);
        if(n<m) while(diff--) vt.push_back(0);
        if(m<n) while(diff--) wt.push_back(0);
        int add=3; while(add--) vt.push_back(0);
        add=3; while(add--) wt.push_back(0);
        int carry=0; assert((int)vt.size()==(int)wt.size());
        ListNode * head=nullptr,*curr=nullptr;
        for(int i=0;i<(int)vt.size();++i){
            int val=carry+vt[i]+wt[i];
            carry=val/10; val%=10;
            ListNode * tmp = new ListNode(val);
            if(head==nullptr){
                head=tmp;
                curr=tmp;
            }else {
                curr->next=tmp;
                curr=tmp;
            }
        }
        int z=0,tt=0; ListNode* tmp=head; while(tmp!=nullptr){
            if(tmp->val==0) ++z;
            else z=0;
            tmp=tmp->next;
            tt++;
        }
        int keep=tt-z;
        if(keep!=0){
            int trans=keep-1;
            tmp=head; while(trans--) tmp=tmp->next;
            tmp->next=nullptr;
        }else head=new ListNode(0); 
        if(head==nullptr)
            head=new ListNode(0);
        return head;
    }
};
