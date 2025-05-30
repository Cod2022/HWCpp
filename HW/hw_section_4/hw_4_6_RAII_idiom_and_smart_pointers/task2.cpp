/*
Вася разрабатывает новую систему для проведения олимпиад по программированию. 
Ему поручено разработать класс Monitor, хранящий результаты участников по каждой задаче. 
Этот класс должен уметь очень быстро возвращать текущие результаты отдельного участника, 
команды и общие результаты — ведь во время финального этапа на сервис будет приходить большая нагрузка. 
Каждый может наблюдать в мониторе только за интересующим его срезом — например, только за одной командой.

Васе уже дан готовый класс ParticipantResults, описывающий результаты одного участника:
*/
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

struct ParticipantResults {
    std::string login;
    std::string team;
    std::map<std::string, int> scores;  // номер задачи -> баллы

    // ...

    ParticipantResults(const std::string& l, const std::string& te): login(l), team(te) {
    }

    ParticipantResults(const ParticipantResults&) = delete;
    ParticipantResults& operator = (const ParticipantResults&) = delete;
};
/*
Его изменить вы не можете. Класс может быть «тяжёлым» в инициализации и копировании. 
Чтобы не создавались лишние копии этого класса, его конструктор копирования и оператор присваивания вообще удалены.

В классе Monitor, который пишет Вася, должны быть следующие функции:

1. RegisterParticipant(const std::string& login, const std::string& team) — регистрирует участника в указанной команде и возвращает (в каком-то виде) созданный для него ParticipantResults. Если участник с таким логином уже зарегистрирован, то выбрасывает исключение std::invalid_argument.

2. GetParticipantResults(const std::string& login) — получает (в каком-то виде) ParticipantResults для данного участника. Если такого логина нет, выкидывает std::out_of_range. Должна быть константная версия (для отрисовки результатов) и неконстантная (для обновлений результатов после очередной посылки).

3. GetTeamResults(const std::string& team) const — возвращает (в каком-то виде) контейнер из ParticipantResults для данной команды. Если такой команды нет, выкидывает std::out_of_range.

4. GetAllResults() const — возвращает (в каком-то виде) контейнер всех результатов.

Вася решил, что будет хранить вектор указателей на результаты для каждой команды и общие результаты. 
Указатели позволят ему сделать результаты «общими» в каждом из этих векторов и не составлять такие 
векторы заново при каждом вызове функций GetTeamResults или GetAllResults. Вот заготовка Васи:
*/

class Monitor {
private:
    // удобные псевдонимы типов для краткости:
    using Ptr = ParticipantResults*;
    using ConstPtr = const ParticipantResults*;

    std::map<std::string, Ptr> byParticipant;
    std::map<std::string, std::vector<ConstPtr>> byTeam;
    std::vector<ConstPtr> allResults;

public:
    Monitor() = default;
    Monitor(const Monitor&) = delete;
    Monitor& operator=(const Monitor&) = delete;

    Ptr RegisterParticipant(const std::string& login, const std::string& team) {
        if (byParticipant.contains(login)) {
            throw std::invalid_argument("Participant is already registered");
        }
        // Добавить новую запись об участнике и вернуть её
    }

    Ptr GetParticipantResults(const std::string& login) {
        return byParticipant.at(login);
    }

    ConstPtr GetParticipantResults(const std::string& login) const {
        return byParticipant.at(login);
    }

    std::vector<ConstPtr> GetTeamResults(const std::string& team) const {
        return byTeam.at(team);
    }

    std::vector<ConstPtr> GetAllResults() const {
        return allResults;
    }
};


// Использоваться этот класс будет примерно так:
int main() {
    Monitor monitor;

    {
        auto ptr = monitor.RegisterParticipant("Ivanov Ivan", "201-1");
        ptr->scores["A"] = 10;
        ptr->scores["B"] = 8;
    }

    {
        auto ptr = monitor.RegisterParticipant("Petrov Petr", "201-2");
        ptr->scores["A"] = 5;
        ptr->scores["C"] = 10;
    }

    auto ptr = monitor.GetParticipantResults("Ivanov Ivan");
    ptr->scores["Q"] = 100;

    // тут может быть аналогичный вызов monitor.GetTeamResults(team)
    for (const auto& result : monitor.GetAllResults()) {
        std::cout << result->login << "\t" << result->team << "\t";
        for (const auto& [problemId, score] : result->scores) {
            std::cout << problemId << ": " << score << "\t";
        }
        std::cout << "\n";
    }
}