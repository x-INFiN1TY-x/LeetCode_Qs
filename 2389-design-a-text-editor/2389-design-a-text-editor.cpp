class List{
  public:
    char val;
    List* next,*prev;
    
    List(char v){
        val=v;
        next=prev=NULL;
    }
    
    List(char v,List* a,List* b){
        val=v;
        next=a;
        prev=b;
    }
};

class TextEditor {
public:
    List* head,* pointer;
    
    TextEditor() {
        head=new List('0');
        pointer=head;
    }
    
    void addText(string text) {
        
        List* p=pointer->next;
        int n=text.size();
        
        for(int i=0;i<n;i++){
            auto e=new List(text[i],NULL,pointer);
            pointer->next=e;
            pointer=pointer->next;
        }
        
        pointer->next=p;
        if(p)p->prev=pointer;
    }
    
    int deleteText(int k) {
        List* p=pointer->next;
        
        
        int a=0;
        while(a!=k && pointer!=head){
            pointer=pointer->prev;
            pointer->next=NULL;
            a++;
        }
                
        pointer->next=p;
        if(p)p->prev=pointer;
        
        return a;
    }
    
    string cursorLeft(int k) {
        int a=0;
        while(a!=k && pointer!=head){
            pointer=pointer->prev;
            a++;
        }
    
        auto t=pointer;
        int len=10;
        string ans="";
        
        while(t!=head && len!=0){
            ans+=t->val;
            t=t->prev;
            len--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        int a=0;
        while(a!=k && pointer->next!=NULL){
            pointer=pointer->next;
            a++;
        }
        
        auto t=pointer;
        int len=10;
        string ans="";
        
        while(t!=head && len!=0){
            ans+=t->val;
            t=t->prev;
            len--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};