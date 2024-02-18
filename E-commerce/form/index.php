<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<h1>Form Data Submission</h1>
<form action="process.php" method="post">
  <label for="name">Name:</label>
  <input type="text" id="name" name="name" required>
  <br>
  <label for="email">Email:</label>
  <input type="email" id="email" name="email" required>
  <br>
  <label for="message">Message:</label>
  <textarea id="message" name="message" rows="5" cols="30" required></textarea>
  <br>
  
  <br>
  <input type="submit" value="Submit">
  <input type="reset" value="Reset">
</form>
</body>
</html>