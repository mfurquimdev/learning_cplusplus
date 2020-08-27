// promise example
#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

void print_int (std::future<int>& fut) {
  std::chrono::milliseconds span (100);
  while (fut.wait_for(span)==std::future_status::timeout)
    std::cout << '.' << std::flush;

  int x = fut.get();
  std::cout << "\nvalue: " << x << '\n';
}

int main ()
{
  std::promise<int> prom;                      // create promise

  std::future<int> fut = prom.get_future();    // engagement with future

  std::thread th1 (print_int, std::ref(fut));  // send future to new thread

	std::this_thread::sleep_for (std::chrono::seconds(3));
  prom.set_value (10);                         // fulfill promise
                                               // (synchronizes with getting the future)
  th1.join();
  return 0;
}
