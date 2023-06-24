#ifndef METRIC_H
#define METRIC_H

#include <iostream>
#include <map>

class MetricRegister {
public:
  static MetricRegister &getInstance() {
    static MetricRegister instance;
    return instance;
  }

  bool add_metr(int key, int resp_t, int wait_t) {
    if (key <= 0 || resp_t < 0 || wait_t < 0 ||
        metrics.find(key) != metrics.end()) {
      return false; // Метрика уже существует
    }
    metrics[key] = std::make_pair(resp_t, wait_t);
    return true;
  }

  bool show_metr() {
    if (metrics.empty()) {
      return false; // Метрики не найдены
    }
    std::cout << "Ключ\tВремя отклика\tВремя ожидания" << std::endl;
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

#endif // METRIC_H