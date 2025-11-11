#pragma once

class Actor; // Forward declaration, бо Actor буде включати компоненти

class Component {
public:
    Actor* Actor = nullptr;  // Вказівник на власника компонента

    virtual ~Component() = default;

    /// @brief Викликається при додаванні компонента до актора
    virtual void OnAdd(Actor& owner) {}

    /// @brief Викликається кожен кадр
    virtual void Tick(float DeltaTime) {}
};
