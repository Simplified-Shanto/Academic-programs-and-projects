# Java Practice Codes

## Compile and run the PrepSmith practice

From this top-level directory, run:

```bash
cd nested_package
javac prepsmith/app/Main.java
java prepsmith.app.Main
```

## Remove compiled class files

From this directory, run:

```bash
find . -type f -name '*.class' -delete
```

This removes only compiled Java `.class` files inside this practice directory; it does not remove any `.java` source files.
