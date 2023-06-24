#include <iostream>
#include <map>

class MetricRegister {
public:
  static MetricRegister &getInstance() {
    static MetricRegister instance;
    return instance;
  }

  bool add_metr(int key, int resp_t, int wait_t) {
    if (metrics.find(key) != metrics.end()) {
      return false; // Метрика уже существует
    }
    metrics[key] = std::make_pair(resp_t, wait_t);
    return true;
  }

  bool show_metr() {
    if (metrics.empty()) {
      return false; // Метрики не найдены
    }
    std::cout << "Key\tResponse Time\tWait Time" << std::endl;
    for (auto const &[key, metric] : metrics) {
      std::cout << key << "\t" << metric.first << "\t\t" << metric.second
                << std::endl;
    }
    return true;
  }

  int count_cometr(int key) {
    if (metrics.find(key) == metrics.end()) {
      return -1; // Метрика не найдена
    }
    return metrics[key].first + metrics[key].second;
  }

private:
  std::map<int, std::pair<int, int>> metrics;

  MetricRegister() {}
  MetricRegister(const MetricRegister &) = delete;
  MetricRegister &operator=(const MetricRegister &) = delete;
  ~MetricRegister() {}
};

int main() {
  MetricRegister &registry = MetricRegister::getInstance();

  // Добавляем метрики
  registry.add_metr(1, 10, 5);
  registry.add_metr(2, 20, 10);
  registry.add_metr(3, 15, 8);

  // Выводим метрики на экран
  registry.show_metr();

  // Вычисляем вспомогательную метрику
  int cometr = registry.count_cometr(2);
  if (cometr != -1) {
    std::cout << "COMETR for key 2: " << cometr << std::endl;
  } else {
    std::cout << "Metric not found" << std::endl;
  }

  return 0;
}