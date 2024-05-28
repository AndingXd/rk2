#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.cpp"
#include <string>

TEST(MementoTest, ConstructorSetsState) {
    std::string expectedState = "Hello";
    ConcreteMemento memento(expectedState);

    ASSERT_EQ(memento.state(), expectedState);
}

TEST(LoggerTest, UndoRestoresPreviousState) {
    TextEditor editor;
    Logger logger(&editor);

    editor.AppendText("Hello");
    logger.Backup();

    editor.AppendText(" Dear Amin");
    std::string expectedText = "Hello Dear Amin";

    logger.Undo();
    ASSERT_EQ(editor.GetText(), expectedText);
}

TEST(LoggerTest, UndoRestoresPreviousState) {
    TextEditor editor;
    Logger logger(&editor);

    editor.AppendText("Hello");
    logger.Backup();

    editor.AppendText(" Dear Amin");
    editor.Print();
    std::string expectedOutput = "Hello Dear Amin";

    logger.Undo();
    editor.Print();
    ASSERT_EQ(testing::internal::GetCapturedStdout(), expectedOutput);
}



