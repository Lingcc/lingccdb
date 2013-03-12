#include <boost/thread/thread.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void hello() {
  std::cout << "Hello world, I am a thread!" << std::endl;
  try{
    for(int i=0; i  < 5; ++i) {
      wait(1);
      std::cout << i << std::endl;
    }
  } catch(boost::thread_interrupted&){
    std::cout << "Interrupted!" << std::endl;
  }
}

int main() {
  boost::thread thrd(&hello);
  wait(3);
  thrd.interrupt();
  thrd.join();
  return 0;
}
