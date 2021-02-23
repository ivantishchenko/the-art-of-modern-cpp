#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class PriorityCollection {
public:
  using Id = int;

   // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object) {
    const Id new_id = objects_.size();
    objects_.push_back({move(object)});
    sorted_objects_.insert({0, new_id});
    return new_id;
  }

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end, IdOutputIt ids_begin) {
      for(ObjInputIt it = range_begin; it != range_end; ++it) {
        *ids_begin++ = Add(move(*it));
      }
  }

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const {
      return objects_.size() && id >= 0 && objects_[id].priority != NONE_PRIORITY;
  }

  // Получить объект по идентификатору
  const T& Get(Id id) const {
      return objects_[id].data;
  }

  // Увеличить приоритет объекта на 1
  void Promote(Id id) {
    auto& item = objects_[id];
    const int old_priority = item.priority;
    const int new_priority = ++item.priority;
    sorted_objects_.erase({old_priority, id});
    sorted_objects_.insert({new_priority, id});
  }

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const {
    const auto& item = objects_[prev(sorted_objects_.end())->second];
    return {item.data, item.priority};
  }

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax() {
    const auto sorted_objects_it = prev(sorted_objects_.end());
    auto& item = objects_[sorted_objects_it->second];
    sorted_objects_.erase(sorted_objects_it);
    const int priority = item.priority;
    item.priority = NONE_PRIORITY;
    return {move(item.data), priority};
  }

  void PrintObjects() {
      for(const ObjectItem& item : objects_) {
          cout << item.data << " " << item.priority << endl;
      }
      cout << endl;
  }

  size_t GetObjectsSize() {
      return objects_.size();
  }

private:
    struct ObjectItem {
        T data;
        int priority = 0;
    };

    static const int NONE_PRIORITY = -1;

    vector<ObjectItem> objects_;
    set<pair<int, Id>> sorted_objects_;
};

class StringNonCopyable : public string {
public:
  using string::string;  // Позволяет использовать конструкторы строки
  StringNonCopyable(const StringNonCopyable&) = delete;
  StringNonCopyable(StringNonCopyable&&) = default;
  StringNonCopyable& operator=(const StringNonCopyable&) = delete;
  StringNonCopyable& operator=(StringNonCopyable&&) = default;
};

void TestNoCopy() {
  PriorityCollection<StringNonCopyable> strings;
  const auto white_id = strings.Add("white");
  const auto yellow_id = strings.Add("yellow");
  const auto red_id = strings.Add("red");

  const int original_size = strings.GetObjectsSize();

  strings.Promote(yellow_id);
  for (int i = 0; i < 2; ++i) {
    strings.Promote(red_id);
  }
  strings.Promote(yellow_id);
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "red");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "yellow");
    ASSERT_EQUAL(item.second, 2);
  }
  {
    const auto item = strings.PopMax();
    ASSERT_EQUAL(item.first, "white");
    ASSERT_EQUAL(item.second, 0);
  }
  {
    const int curr_size = strings.GetObjectsSize();
    ASSERT_EQUAL(curr_size, original_size);
  }
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestNoCopy);
  return 0;
}
