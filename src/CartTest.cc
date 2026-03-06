#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cart.h"
#include "Item.h"
#include "ItemService.h"
#include <vector>
#include <iostream>

using ::testing::_;
using ::testing::Return;

class MockItemService : public ItemService
{
public:
    MOCK_METHOD(double, getPrice, (Item & item), (override));
};

class CartTest : public ::testing::Test
{
protected:
    std::vector<Item> items;
    MockItemService mockItemService;
    double totalAmount;

    // Also adds expect call for the getPrice function on the mocked service
    void addExpectedCartItem(Item item, double price)
    {
        items.push_back(item);
        EXPECT_CALL(mockItemService, getPrice(item)).WillOnce(Return(price));
        totalAmount += price * item.getQuantity();
    }

    void SetUp() override
    {
        std::cout << "SetUp: Preparing the test environment..." << std::endl;
        totalAmount = 0.0;
    }

    void TearDown() override
    {
        std::cout << "TearDown: Cleaning up after test..." << std::endl;
        items.clear();
    }
};

// handles no items (returns 0)
TEST_F(CartTest, GetCartNoItems)
{
    Cart cart;
    cart.setItemService(&mockItemService);

    EXPECT_EQ(cart.getCartTotalAmount(), 0);
}

// handles null service (returns 0)
TEST_F(CartTest, GetCartNullPointerService)
{
    items.push_back(Item("1", "SDcard", 1));

    Cart cart;
    cart.setItemService(nullptr);
    cart.setItems(items);

    EXPECT_EQ(cart.getCartTotalAmount(), 0);
}

// handles 1 item
TEST_F(CartTest, GetCartOneItemTotalAmount)
{
    addExpectedCartItem(Item("1", "SDcard", 1), 10.0);

    Cart cart;
    cart.setItemService(&mockItemService);
    cart.setItems(items);

    EXPECT_EQ(cart.getCartTotalAmount(), totalAmount);
}

// handles multiple items
TEST_F(CartTest, GetCartMultipleItemsTotalAmount)
{
    addExpectedCartItem(Item("1", "SDcard", 1), 10.0);
    addExpectedCartItem(Item("2", "LEDlight", 1), 20.0);
    addExpectedCartItem(Item("3", "DashCam", 2), 30.0);

    Cart cart;
    cart.setItemService(&mockItemService);
    cart.setItems(items);

    EXPECT_EQ(cart.getCartTotalAmount(), totalAmount);
}

// handles 1 item with 2 quantity
TEST_F(CartTest, GetCartOneItemTwoQuantityTotalAmount)
{
    addExpectedCartItem(Item("1", "SDcard", 2), 10.0);

    Cart cart;
    cart.setItemService(&mockItemService);
    cart.setItems(items);

    EXPECT_EQ(cart.getCartTotalAmount(), totalAmount);
}