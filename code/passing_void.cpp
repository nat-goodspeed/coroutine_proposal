std::execution_context<void> ctx1([](std::execution_context<void> ctx2){
            std::printf("inside ctx1\n");
            return ctx2();
        });
ctx1();

output:
    inside ctx1
