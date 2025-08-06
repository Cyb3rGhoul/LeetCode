SELECT name as Customers
FROM Customers c
WHERE c.id NOT IN (SELECT customerId FROM Orders o WHERE customerId IS NOT NULL);