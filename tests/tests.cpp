#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.cpp"
#include <string>

// Тест для конструктора класса ConcreteMemento
TEST(ConcreteMemento, Constructor) {
    const std::string expectedState = "initial state";
    ConcreteMemento memento(expectedState);

    EXPECT_EQ(memento.state(), expectedState);
}

// Тест для метода state() класса ConcreteMemento
TEST(ConcreteMemento, State) {
    const std::string state = "current state";
    ConcreteMemento memento(state);

    EXPECT_EQ(memento.state(), state);
}

// Тест для метода Undo() класса Logger
TEST(Logger, Undo) {
    TextEditor editor;
    Logger logger(&editor);

    // Добавляем текст к редактору
    editor.AppendText("initial text");

    // Создаем резервную копию состояния
    logger.Backup();

    // Добавляем больше текста к редактору
    editor.AppendText(" additional text");

    // Восстанавливаем состояние из резервной копии
    logger.Undo();

    // Проверяем, что изменения, внесенные после создания резервной копии, были отменены
    EXPECT_EQ(editor.GetText(), "initial text");
}



