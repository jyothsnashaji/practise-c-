class LRUCache
{
    private:
    
    static unordered_map<int,Node *> hsmap;
    static int capacity,count;
    static Node *head,*tail;
   
    public:

    LRUCache(int cap)
    {
       capacity=cap;
       count=0;//Your code here
       head=NULL;
       tail=NULL;
    }
  
    static int get(int key)
    {
        auto pos=hsmap.find(key);
        int ret;
       if( pos !=hsmap.end())
       {
           ret=(pos->second)->value;
           (pos->second )->pre=(pos->second )->next;
           tail->next=pos->second;
           tail=tail->next;
           
           
       }
       else
       {
           ret=-1;
       }
       return ret;
    }
    
    static void set(int key, int value)
    {
        if (count==capacity)
        {
            hsmap.erase(head->key);
            head=head->next;
            --count;
        }
        
        if(head==NULL)
        {
            head=new Node(key,value);
            tail=head;
          
        }
        else
       {tail->next=new Node(key,value);
        tail->next->pre=tail;
        tail=tail->next;
       }
       hsmap.insert(make_pair(key,tail));
       ++count;
      
       
    }
    
};