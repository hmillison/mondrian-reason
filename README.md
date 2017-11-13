# Mondrian

Create art inspired by Piet Mondrian in your browser.

As someone who enjoys developing for the web, I wanted to explore alternatives to JS for creating an interactive experience.

When doing modern web app development, we're already going through some sort of compile/build step with Babel and Webpack. At that point, why not explore using a different language that compiles to JS?

This is my first time using ReasonML. It is a pretty interesting alternative since the syntax feels similar to JS, but with all of the type safeness of Ocaml. I've been impressed so far with its ability to catch errors as I'm working on this project.

## Running this project locally 
```
yarn
yarn start
# in another tab
yarn webpack
```

After you see the webpack compilation succeed, open up the nested html files in `src/*` (**no server needed!**). Then modify whichever file in `src` and refresh the page to see the changes.
