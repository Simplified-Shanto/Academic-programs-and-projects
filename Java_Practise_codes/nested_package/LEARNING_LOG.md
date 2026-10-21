# PrepSmith learning log

This document records what has been practised and what is intentionally deferred, so the project can grow without losing its learning path.

## Practised

### Packages and imports

- `prepsmith.app` contains the program entry point (`Main`).
- `prepsmith.users` contains student-related data and lookup behavior.
- `prepsmith.learning` contains learning behavior and sessions.
- `prepsmith.reports` contains reporting behavior.
- Package names match the directory hierarchy.
- `import` shortens a class name; `prepsmith.reports.ProgressReporter` demonstrates a fully qualified class name without an import.

### Access control

| Member | Access level | Purpose in PrepSmith |
|---|---|---|
| `email` | `private` | Only `Student` can access it directly. |
| `studentId` | package-private | Classes in `prepsmith.users`, such as `StudentIdLookup`, can access it directly. |
| `weeklyGoal` | `protected` | `Student` subclasses can access it. |
| `getName()` / `getMaskedEmail()` | `public` | Any package, such as `ProgressReporter`, can call them. |

### Inheritance, abstraction, and interfaces

- `Student` is an abstract base class: it holds common student data but cannot be created directly.
- `Student` implements `Learner`, so every concrete student type must provide `learn()` and `getProgressSummary()`.
- `MathStudent`, `VocabularyStudent`, and `ScienceStudent` extend `Student` and implement those learner behaviors differently.
- `LearningSession` accepts `Learner[]`, allowing it to work with all learner types through one common interface.

## Current functional flow

```text
Main creates concrete students
→ stores them as Learner references
→ LearningSession runs learning behavior and shows progress
→ ProgressReporter displays public student information
```

See [ARCHITECTURE.md](ARCHITECTURE.md) for the component graph.

## Deferred for a future revisit

### Nested interfaces and session observers

The PDF introduces nested interfaces. A possible future design is:

```text
LearningSession starts
→ notifies a LearningSession.SessionObserver
→ logger, notification service, or database handler responds
```

This is useful only when a real feature needs session logging, notifications, analytics, or persistence. Do not add it merely to demonstrate the syntax.

### InternalStudentValidator

`InternalStudentValidator` is a package-private helper experiment. Revisit it when PrepSmith needs actual student-ID validation rules. Until then, it is not part of the main functional flow.

## Next learning direction

Make learning update real progress state instead of only printing messages. This will make a session have a lasting effect that can later be reported.
