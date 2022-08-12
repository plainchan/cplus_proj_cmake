#ifndef NESTED_CLASS_HPP
#define NESTED_CLASS_HPP





class Handle
{
public:
    Handle():impl_(new HandleImpl){}
    void doProcess()
    {
        impl_->doProcess();
    }
    
private:
    class HandleImpl
    {
        public:
        void doProcess()
        {
            std::cout << "Handle process" << std::endl;
        }
    };

    HandleImpl *impl_;
};










#endif