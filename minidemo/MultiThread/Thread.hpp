class Thread {
public:
  Thread();
  int Start(void * arg);

protected:
  int Run(void* arg);
  static void* EntryPoint(void*);
  virtual void Setup();
  virtual void Execute(void*);
  void* Arg() const { return Arg_; }
  void Arg(void* a){Arg_ = a;}
private:
  THREADID ThreadId_;
  void* Arg_;
};

// The constructor
Thread::Thread() {
}

// Start the thread by create it, and record the args for thread.
int Thread::Start(void* arg) {
  Arg(arg); // store user data
  int code = thread_create(Thread::EntryPoint, this, &ThreadId_);
  return code:
}


// Protected function that should never be tampered with.
int Thread::Run(void* arg) {
  Setup();
  Execute(arg);
}


// Serves as the entry point to the thread.
/* static */
void* Thread::EntryPoint(void* pthis) {
  Thread* pt = (Thread*)pthis;
  pthis->Run(Arg());
}

// Called after the thread have been created but before Executed() is called.
virtual void Thread::Setup() {
  //Do any setup here
}

// function need to be overwrite.
virtual void Thread::Execute(void* arg) {
  // the thread code
}
