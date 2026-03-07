# Student Management System

A C++ console application for managing student records with SQLite database. Supports login, account creation, CRUD operations on students and courses, with role-based access (Admin/Staff).

## Features

### Authentication
- **Login** — Sign in with username and password
- **Create Account** — Register new users with role (Admin/Staff)
- **Role-based Access** — Admin can delete; Staff has limited permissions

### Student Management
- **Add Student & Courses** — Add students with up to 5 courses and grades
- **Show All Students** — Display students in formatted table with GPA and rating
- **Search Student** — Search by ID in database
- **Delete Student** — Remove student (Admin only)
- **Update Student** — Modify name and age

## Project Structure

```
StudentManagement/
├── main.cpp                    # Entry point
├── app.cpp                     # Main loop, menu, auth flow
├── models/
│   ├── header.h                # Main header (all dependencies)
│   └── studentes_model.h       # Student & Course structs
├── database/
│   ├── database.cpp/h          # DB initialization (create tables)
├── services/
│   ├── CRUD_service/
│   │   ├── add_servic.cpp/h       # Add student + courses
│   │   ├── show_servic.cpp/h      # Display students
│   │   ├── search_servic.cpp/h    # Search by ID
│   │   ├── delete_servic.cpp/h    # Delete student
│   │   ├── update_servic.cpp/h    # Update student
│   │   └── sort_servic.cpp/h      # Sort by ID
│   ├── saveing_service/
│   │   ├── saveing_service.cpp/h     # CSV import/export
│   │   ├── saving_in_database.cpp/h  # Save student to DB
│   │   ├── load_service.cpp         # Load students from DB
│   │   ├── update_servic.cpp        # Update student in DB
│   │   └── database_service.h       # load_students, update_student
│   ├── auth_service/
│   │   └── auth_service.cpp/h    # Login, register
│   └── GPA_service/
│       └── gpa_service.cpp/h     # GPA calculation, rating
├── sqlite3/
│   └── sqlite3.c/h              # SQLite
└── students_data.csv            # CSV backup
```

## Build & Run

### Compile (g++ / MinGW)

```bash
g++ main.cpp app.cpp database/database.cpp services/CRUD_service/*.cpp services/saveing_service/*.cpp services/auth_service/*.cpp services/GPA_service/*.cpp sqlite3/sqlite3.c -o student_app.exe -I.
```

### Run

```bash
./student_app.exe
```

On **Windows** (PowerShell/CMD):

```bash
.\student_app.exe
```

> Run from the project root directory.

## Database Schema & Flowchart

### Entity Relationship Diagram

```mermaid
erDiagram
    Users ||--o{ UserStudentLink : "has"
    Students ||--o{ StudentCourses : "enrolled in"
    Courses ||--o{ StudentCourses : "has grades"
    
    Users {
        int UserID PK
        string Username UK
        string Password
        string Role
    }
    
    Students {
        int StudentID PK
        string Name
        int Age
        string Level
    }
    
    Courses {
        int CourseID PK
        string CourseName
        int Credits
    }
    
    StudentCourses {
        int StudentID FK
        int CourseID FK
        float Grade
    }
```

### Database Tables Structure

```mermaid
flowchart TB
    subgraph Tables["Database Tables (system_data.db)"]
        Users["Users<br/>UserID (PK)<br/>Username (UNIQUE)<br/>Password<br/>Role"]
        Students["Students<br/>StudentID (PK)<br/>Name<br/>Age<br/>Level"]
        Courses["Courses<br/>CourseID (PK)<br/>CourseName<br/>Credits"]
        StudentCourses["StudentCourses<br/>StudentID (FK)<br/>CourseID (FK)<br/>Grade"]
    end
    
    Students -->|"1:N"| StudentCourses
    Courses -->|"1:N"| StudentCourses
    StudentCourses -->|"N:1"| Students
    StudentCourses -->|"N:1"| Courses
```

### Data Flow — How the Database is Used

```mermaid
flowchart LR
    subgraph Auth["Authentication"]
        A1[Login/Register] --> Users[(Users Table)]
    end
    
    subgraph Add["Add Student"]
        A2[Add Student] --> Students[(Students)]
        A2 --> Courses[(Courses)]
        A2 --> SC[(StudentCourses)]
    end
    
    subgraph Read["Read Data"]
        Students --> L1[Load Students]
        Courses --> L1
        SC --> L1
        L1 --> Display[Show/Search]
    end
    
    subgraph Update["Update"]
        U1[Update Service] --> Students
    end
    
    subgraph Delete["Delete"]
        D1[Delete Service] --> Students
    end
```

### Table Details

| Table | Column | Type | Description |
|-------|--------|------|-------------|
| **Users** | UserID | INTEGER PK | Auto-increment |
| | Username | TEXT UNIQUE | Login name |
| | Password | TEXT | Password |
| | Role | TEXT | Admin / Staff |
| **Students** | StudentID | INTEGER PK | Student ID |
| | Name | TEXT | Student name |
| | Age | INTEGER | Age |
| | Level | TEXT | Study level |
| **Courses** | CourseID | INTEGER PK | Auto-increment |
| | CourseName | TEXT | Course name |
| | Credits | INTEGER | Default 3 |
| **StudentCourses** | StudentID | INTEGER FK | → Students |
| | CourseID | INTEGER FK | → Courses |
| | Grade | REAL | Course grade |

## Application Flowchart

```mermaid
flowchart TD
    Start([Start]) --> Init[Initialize DB]
    Init --> AuthMenu{1. Login / 2. Create Account}
    AuthMenu -->|2| Register[Register User]
    Register --> AuthMenu
    AuthMenu -->|1| Login[Enter Credentials]
    Login --> Check{Valid?}
    Check -->|No| Deny[Access Denied]
    Check -->|Yes| Load[Load Students from DB]
    Load --> Menu[Main Menu]
    
    Menu --> Choice{Choice}
    Choice -->|1| Add[Add Student + 5 Courses]
    Choice -->|2| Show[Show All Students]
    Choice -->|3| Search[Search by ID]
    Choice -->|4| Delete[Delete Student - Admin only]
    Choice -->|5| Update[Update Student]
    Choice -->|0| Exit([Exit])
    
    Add --> DB1[(Students + Courses + StudentCourses)]
    Delete --> DB1
    Update --> DB1
    Search --> DB1
    Show --> Display[Display Table]
    
    Add --> Load
    Delete --> Load
    Update --> Load
    Display --> Menu
```

## Data Model (C++)

| Field | Type | Description |
|-------|------|-------------|
| `id` | int | Student ID |
| `name` | string | Student name |
| `age` | int | Age |
| `study_level` | string | Level (e.g. Bachelor, Master) |
| `course[5]` | course[] | Up to 5 courses |
| `gpa` | double | Calculated GPA |

### Course struct

| Field | Type |
|-------|------|
| `course_name` | string |
| `grade` | double |
| `credits` | int (default 3) |

## CSV Format

```
ID,Name,Age,Level
1,John Doe,20,Bachelor
2,Jane Smith,22,Master
```
