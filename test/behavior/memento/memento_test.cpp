/// @file memento_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-28
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/memento/memento.h"

#include <gtest/gtest.h>

#include <iostream>

namespace
{
using namespace design_pattern::behavior::memento;

TEST(MementoTest, MementoCreate)
{
    Memento m("state string");
    EXPECT_EQ(m.State(), "state string");
}

TEST(MementoTest, OriginatorCreate)
{
    Originator o("state string");
    EXPECT_EQ(o.State(), "state string");
}

TEST(MementoTest, OriginatorSave)
{
    Originator o("state string");
    Memento m = o.Save();
    EXPECT_EQ(m.State(), "state string");
    EXPECT_EQ(m.State(), o.State());
}

TEST(MementoTest, OriginatorRestore)
{
    Memento m("state string");
    Originator o;
    o.Restore(m);
    EXPECT_EQ(o.State(), "state string");
    EXPECT_EQ(o.State(), m.State());
}

TEST(MementoTest, CaretakerCreate)
{
    Caretaker c;
    c.Update("1");
    EXPECT_EQ(c.State(), "1");
}

TEST(MementoTest, CaretakerUpdate)
{
    Caretaker c;
    c.Update("1");
    c.Update("2");
    EXPECT_EQ(c.State(), "2");
}

TEST(MementoTest, CaretakerUndo)
{
    Caretaker c;
    c.Update("1");
    c.Update("2");
    c.Undo();
    EXPECT_EQ(c.State(), "1");
}

}  // namespace
