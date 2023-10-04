# Library Management System

This is a simple Library Management System implemented in C++. It allows both administrators and students to interact with the library's inventory. Administrators can add and delete books, while students can view categories, borrow and return books.

## Features

- **Admin Menu**:
  - Add a book to the library.
  - Delete a book from the library.
  - Display the library inventory.
  - Display records (currently not implemented).
  - Logout from the admin account.

- **Student Menu**:
  - View book categories(implemented)
  - Borrow a book (currently not implemented).
  - Return a book (currently not implemented).
  - Logout from the student account.

## Usage

1. Compile the code using a C++ compiler.

2. Run the compiled executable.

3. You will be prompted to enter your username and password:
   - For admin access, use the following credentials:
     - Username: `admin`
     - Password: `admin`
   - For student access, use the following credentials:
     - Username: `student123`
     -password:  `password123`

4. Follow the menu prompts to interact with the library management system.

## Categories

Books can be categorized into the following categories:
1. Story
2. Poetry
3. Course Book
4. Novel
5. Drama
6. Other (default if an invalid category is chosen)

## File Structure

- `main.cpp`: The main C++ source code file.
- `readme.md`: This README file.
- `category.txt` (and others): Text files used to store book records categorized by type.
- `category_temp.txt` (and others): Temporary files used during book deletion.

## Author

- Author: Kewal Dahal
- Email: kewaldahal34@email.com

## License

This code is provided under the MIT License.

MIT License

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
