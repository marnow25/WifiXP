template <class Type>
 class Singleton {
 public:
     static Type &GetInstance() {
         static Instance instance;
         return instance;
 }
 private:
     virtual void SingletonCannotBeInstantiated() = 0;

     class Instance : public Type {
     private:
         void SingletonCannotBeInstantiated() {}
     };
 };
