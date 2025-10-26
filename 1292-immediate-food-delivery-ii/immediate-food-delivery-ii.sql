SELECT 
    ROUND(
        SUM(order_date = customer_pref_delivery_date) * 100 / COUNT(*),
        2
    ) AS immediate_percentage
FROM (
    SELECT 
        customer_id,
        MIN(order_date) AS order_date,
        MIN(customer_pref_delivery_date) AS customer_pref_delivery_date
    FROM Delivery
    GROUP BY customer_id
) AS first_orders;
