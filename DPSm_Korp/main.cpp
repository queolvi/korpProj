
/*
#include <iostream>
#include <vector>
#include <chrono>

// Класс Цель
class Target {
public:
    Target(const std::string& name, int health) : name(name), health(health), current_health(health) {}

    void takeDamage(int damage) {
        current_health -= damage;
        if (current_health < 0) {
            current_health = 0;
        }
    }

    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getCurrentHealth() const { return current_health; }

private:
    std::string name;
    int health;
    int current_health;
};

// Класс Персонаж
class Character {
public:
    Character(const std::string& name, int attack, float attackSpeed) : name(name), attack(attack), attackSpeed(attackSpeed) {}

    int dealDamage(Target& target) {
        int damage = attack;
        target.takeDamage(damage);
        return damage;
    }

    std::string getName() const { return name; }
    int getAttack() const { return attack; }
    float getAttackSpeed() const { return attackSpeed; }

private:
    std::string name;
    int attack;
    float attackSpeed;
};

// Класс Урон
class Damage {
public:
    Damage(int amount, std::chrono::high_resolution_clock::time_point time) : amount(amount), time(time) {}

    int getAmount() const { return amount; }
    std::chrono::high_resolution_clock::time_point getTime() const { return time; }

private:
    int amount;
    std::chrono::high_resolution_clock::time_point time;
};

// Класс DPS
class DPS {
public:
    void addDamage(const Damage& damage) { damages.push_back(damage); }

    float calculateDPS() const {
        if (damages.empty()) {
            return 0;
        }
        auto now = std::chrono::high_resolution_clock::now();
        auto totalTime = std::chrono::duration<float>(now - damages[0].getTime());
        if (totalTime.count() > 0) {
            int totalDamage = 0;
            for (const auto& damage : damages) {
                totalDamage += damage.getAmount();
            }
            return static_cast<float>(totalDamage) / totalTime.count();
        }
        return 0;
    }

private:
    std::vector<Damage> damages;
};

int main() {
    // Создаем объект Цель
    Target target("Босс", 1000);

    // Создаем объект Персонаж
    Character character("Игрок", 100, 1.0f);

    // Создаем объект DPS
    DPS dps;

    // Создаем окно SFML
    sf::RenderWindow window(sf::VideoMode(400, 200), "Счётчик урона");

    // Шрифт для текста
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Ошибка загрузки шрифта!" << std::endl;
        return 1;
    }

    // Текст для отображения информации
    sf::Text targetText;
    targetText.setFont(font);
    targetText.setCharacterSize(18);
    targetText.setFillColor(sf::Color::White);
    targetText.setPosition(10, 10);

    sf::Text damageText;
    damageText.setFont(font);
    damageText.setCharacterSize(18);
    damageText.setFillColor(sf::Color::White);
    damageText.setPosition(10, 40);

    sf::Text dpsText;
    dpsText.setFont(font);
    dpsText.setCharacterSize(18);
    dpsText.setFillColor(sf::Color::White);
    dpsText.setPosition(10, 70);

    // Кнопка "Сброс"
    sf::RectangleShape resetButton(sf::Vector2f(100, 30));
    resetButton.setFillColor(sf::Color::Green);
    resetButton.setPosition(150, 150);

    sf::Text resetButtonText;
    resetButtonText.setFont(font);
    resetButtonText.setCharacterSize(14);
    resetButtonText.setFillColor(sf::Color::White);
    resetButtonText.setString("Сброс");
    resetButtonText.setPosition(165, 160);

    // Основной цикл
    auto lastAttackTime = std::chrono::high_resolution_clock::now();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
// Обработка нажатия кнопки "Сброс"
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left &&
                    resetButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    target.takeDamage(target.getCurrentHealth()); // Сбрасываем здоровье цели
                    dps.damages.clear(); // Сбрасываем список уронов
                }
            }
        }

        // Нанесение урона каждые 1 секунду
        auto currentTime = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration<float>(currentTime - lastAttackTime).count() >= 1.0f / character.getAttackSpeed()) {
            int damage = character.dealDamage(target);
            dps.addDamage(Damage(damage, currentTime));
            lastAttackTime = currentTime;
        }

        // Обновление текста
        targetText.setString("Цель: " + target.getName() + " (" + std::to_string(target.getCurrentHealth()) + "/" + std::to_string(target.getHealth()) + ")");
        damageText.setString("Урон: " + std::to_string(character.getAttack()));
        dpsText.setString("DPS: " + std::to_string(dps.calculateDPS()));

        // Отрисовка
        window.clear(sf::Color::Black);
        window.draw(targetText);
        window.draw(damageText);
        window.draw(dpsText);
        window.draw(resetButton);
        window.draw(resetButtonText);
        window.display();
    }

    return 0;
}
*/