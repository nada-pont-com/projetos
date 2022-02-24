SELECT at.name,count(t.TrackId) FROM artists at
INNER JOIN albums ab on ab.ArtistId = at.ArtistId
INNER JOIN tracks t on t.AlbumId = ab.AlbumId
GROUP BY at.name
ORDER BY 2 DESC

SELECT g.name,count(t.TrackId) FROM tracks t
LEFT JOIN genres g on g.GenreId = t.GenreId
GROUP BY g.name
ORDER BY 2 DESC

SELECT t.name,count(i.InvoiceId) FROM tracks t
	LEFT JOIN invoice_items i on t.TrackId=i.TrackId
GROUP BY t.name
ORDER BY 2 DESC

SELECT *
FROM employees e

SELECT e.FirstName as chefe,
	e2.FirstName as empregado 
FROM employees e
INNER JOIN employees e2 on e2.ReportsTo = e.employeeid

SELECT e.FirstName as chefe,
	e2.FirstName as empregado 
FROM employees e
INNER JOIN employees e2 on e2.ReportsTo = e.employeeid
WHERE e.ReportsTo is not  null


SELECT g.firstname 'gerente',
c.firstname 'chefe',
col.firstname 'colaborador'
from employees g
inner join employees c on g.EmployeeId = c.reportsto
inner join employees col on c.EmployeeId = col.reportsto


SELECT c.FirstName as name,SUM(i.Total) as faturado FROM customers c
inner JOIN invoices i on i.CustomerId = c.CustomerId
GROUP by name
ORDER BY 2 DESC

SELECT g.name as name,sum(ii.UnitPrice*ii.Quantity) as vl FROM invoices i
INNER JOIN invoice_items ii on i.InvoiceId = ii.InvoiceId
INNER JOIN tracks t on ii.TrackId=t.TrackId
INNER JOIN genres g on t.GenreId=g.GenreId
GROUP by 1
ORDER BY 2 DESC


SELECT g.Title as name,sum(ii.UnitPrice*ii.Quantity) as vl FROM invoices i
INNER JOIN invoice_items ii on i.InvoiceId = ii.InvoiceId
INNER JOIN tracks t on ii.TrackId=t.TrackId
INNER JOIN albums g on t.AlbumId=g.AlbumId
GROUP by 1
ORDER BY 2 DESC

SELECT a.name as name,sum(ii.UnitPrice*ii.Quantity) as vl FROM invoices i
INNER JOIN invoice_items ii on i.InvoiceId = ii.InvoiceId
INNER JOIN tracks t on ii.TrackId=t.TrackId
INNER JOIN albums g on t.AlbumId=g.AlbumId
INNER JOIN artists a on a.ArtistId=g.ArtistId
GROUP by 1
ORDER BY 2 DESC
