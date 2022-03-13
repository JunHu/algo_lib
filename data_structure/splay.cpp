//https://www.hackerrank.com/contests/w13/challenges/swaps-and-sum/submissions/code/2614257

struct Node{
    int val, size;
    ll sum;
    Node *fa, *s[2];
}buf[N << 1], *nil, *pool;

void init_pool(){
    nil = pool = buf;
    nil->val = -1;
    nil->s[0] = nil->s[1] = nil->fa = nil;
    nil->size = 0;
}

struct Splay{
    Node *root;
    vector<int> ret;
    
    void push_up(Node* x){
        x->size = x->s[0]->size + x->s[1]->size + 1;
        x->sum = x->val + x->s[0]->sum + x->s[1]->sum;
    }
    void init(int a[], int na){
        root = new_node(-inf, nil);
        root->s[1] = new_node(inf, root);
                
        root->s[1]->s[0] = build(a, 0, na - 1, root->s[1]);
        
        push_up(root->s[1]);
        push_up(root);

    }
    Node* build(int a[], int l, int r, Node* f){
        if(l > r) return nil;
        int mid = l + r >> 1;
        Node* cur = new_node(a[mid], f);
        cur->s[0] = build(a, l, mid - 1, cur);
        cur->s[1] = build(a, mid + 1, r, cur);
        push_up(cur);
        return cur;
    }
    Node* new_node(int val, Node* f){
        Node* x = ++pool; 
        x->fa = f;
        x->val = val;
        x->size = 1;
        x->sum = val;
        x->s[0] = x->s[1] = nil;
        return x;
    }
    void rotate(Node* x) {
        Node* y = x->fa;
        int f = y->s[0] == x ;
        y->s[f ^ 1] = x->s[f] ;
        if(x->s[f] != nil) x->s[f]->fa = y ;
        x->fa = y->fa;
        if(x->fa != nil){
            if(x->fa->s[0] == y) x->fa->s[0] = x ;
            else x->fa->s[1] = x;
        }
        x->s[f] = y;
        y->fa = x;
        push_up(y);
    }
    void splay(Node* x, Node* f){
        while(x->fa != f){
            if(x->fa->fa == f) rotate(x) ;
            else{
                Node* y = x->fa , *z = y->fa ;
                if((z->s[0]==y) == (y->s[0]==x)) rotate(y) ;
                else rotate(x) ;
                rotate(x) ;
            }
        }
        push_up(x) ;
        if(x->fa == nil) root = x ;
    }
    void select(int k, Node* f){
        Node* x = root;
        while(x != nil){
            int tmp = x->s[0]->size + 1;
            if(tmp == k) break ;
            else if(tmp > k) x = x->s[0];
            else x = x->s[1], k -= tmp;
        }
        splay(x, f);
    }
    void get(int left, int right){
        left++, right++;
        select(left - 1, nil);
        select(right + 1, root);
    }
    ll query(int left, int right){
        get(left, right);
        Node* x = root->s[1]->s[0];
        return x->sum;
    }
    void update_root(){
        push_up(root->s[1]);
        push_up(root);
    }
    void dfs(Node* x){
        if(x == nil) return;
        dfs(x->s[0]); 
        cout << x->val << ' ';
        dfs(x->s[1]);
    }
}tree[2];
