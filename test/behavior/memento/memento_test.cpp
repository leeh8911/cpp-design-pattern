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

#include <array>
#include <iostream>
#include <thread>

namespace
{
using namespace design_pattern::behavior::memento;

TEST(MementoTest, MementoCreate)
{
    auto timestamp = std::chrono::system_clock::now();
    std::time_t t_time = std::chrono::system_clock::to_time_t(timestamp);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(timestamp.time_since_epoch()) % 1000;
    std::tm tm_time = *std::localtime(&t_time);

    std::ostringstream oss;
    oss << std::put_time(&tm_time, "%F %T");
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();

    Memento m("state string", timestamp);
    EXPECT_EQ(m.State(), "state string");
    EXPECT_EQ(m.Timestamp(), oss.str());
}

TEST(MementoTest, OriginatorCreate)
{
    Originator o("state string");
    EXPECT_EQ(o.State(), "state string");
}

TEST(MementoTest, OriginatorSave)
{
    Originator o("state string");
    IMementoPtr m = o.Save();
    EXPECT_EQ(m->State(), "state string");
    EXPECT_EQ(m->State(), o.State());
    EXPECT_EQ(m->Timestamp(), o.Timestamp());
}

TEST(MementoTest, OriginatorRestore)
{
    auto timestamp = std::chrono::system_clock::now();
    IMementoPtr m = std::make_unique<Memento>("state string", timestamp);

    std::string m_state = m->State();
    std::string m_timestamp = m->Timestamp();

    Originator o;
    o.Restore(std::move(m));

    EXPECT_EQ(o.State(), "state string");
    EXPECT_EQ(o.State(), m_state);
    EXPECT_EQ(o.Timestamp(), m_timestamp);
}

TEST(MementoTest, CaretakerCreate)
{
    Caretaker c;
    c.Update("1");
    EXPECT_EQ(c.State(), "1");
}

TEST(MementoTest, CaretakerUpdate)
{
    using namespace std::chrono_literals;
    Caretaker c;

    c.Update("1");
    auto timestamp1 = c.Timestamp();
    std::this_thread::sleep_for(10ms);

    c.Update("2");
    auto timestamp2 = c.Timestamp();

    EXPECT_EQ(c.State(), "2");
    EXPECT_NE(timestamp1, timestamp2);
}

TEST(MementoTest, CaretakerUndo)
{
    using namespace std::chrono_literals;

    Caretaker c;
    c.Update("1");
    auto timestamp1 = c.Timestamp();
    std::this_thread::sleep_for(10ms);

    c.Update("2");
    auto timestamp2 = c.Timestamp();
    std::this_thread::sleep_for(10ms);

    c.Undo();
    auto timestamp1_2 = c.Timestamp();
    EXPECT_EQ(c.State(), "1");
    EXPECT_NE(timestamp1, timestamp2);
    EXPECT_EQ(timestamp1, timestamp1_2);
}

} // namespace
