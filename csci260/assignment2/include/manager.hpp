#pragma once

class Manager {
public:
  Manager();
  ~Manager();
  
  void subscribe();
  void unsubscribe();
  void show();
  void list();
  void spam();
  void quit();
};
