#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton;

class SingletonDestroyer {
private:
  Singleton *p_instance;

public:
  ~SingletonDestroyer();
  void initialize(Singleton *p);
};

class Singleton {
private:
  static Singleton *p_instance;
  static SingletonDestroyer destroyer;

protected:
  Singleton() {}
  Singleton(const Singleton &);
  Singleton &operator=(Singleton &);
  ~Singleton() {}
  friend class SingletonDestroyer;

public:
  static Singleton &getInstance();
};

#endif // SINGLETON_H
