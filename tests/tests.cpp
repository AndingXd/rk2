#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "main.cpp"
#include <string>

TEST(MementoTest, ConstructorSetsState) {
    std::string expectedState = "Hello";
    ConcreteMemento memento(expectedState);

    ASSERT_EQ(memento.state(), expectedState);
}

TEST(TextEditorTest, AppendText) {
    TextEditor editor;

    editor.AppendText("Hello");
    ASSERT_EQ(editor.GetText(), "Hello");

    editor.AppendText(", world!");
    ASSERT_EQ(editor.GetText(), "Hello, world!");
}

TEST(LoggerTest, UndoRestoresPreviousState2) {
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



