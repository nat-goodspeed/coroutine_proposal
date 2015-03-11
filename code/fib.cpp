// stackful execution_context
#define yield(x) p=x; mctx();
int main(){
    int n=35;
    int p=0;
    std::execution_context mctx(std::execution_context::current());
    std::execution_context ctx(std::make_fixedsize_stack(1024),
                               [n,&p,mctx]()mutable{
                                   int a=0,b=1;
                                   while(n-->0){
                                       yield(a);
                                       auto next=a+b;
                                       a=b;
                                       b=next;
                                   }
                               });
    for(int i=0;i<10;++i){
        ctx();
        std::cout<<p<<std::endl;
    }
}