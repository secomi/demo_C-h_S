# Demo C-h S and how to use info-lookup for function reference

This is a DO nothing application whith the only purpose to test `info-lookmore.el` from:

- [https://user42.tuxfamily.org/info-lookmore/index.html](https://user42.tuxfamily.org/info-lookmore/index.html)
- [https://github.com/emacsmirror/info-lookmore](https://github.com/emacsmirror/info-lookmore)

## Application development 

Standard GNU autotools is used:
1. Generate the Makefiles
       $ autoreconf -i

1. Validate all the libraries
       $ ./configure

1. Compile the small demo project
       make all

1. in the doc/ folder create a `dir` index
        $ install-info demo.info dir

In the `doc/` folder the `demo.info` file has been produced and can be viewed with standard tools. Eg:
```sh
$ info ./demo.info
```
Or from within Emacs `C-u C-h i` and select the `demo.info` file. 

## Emacs configuration
Configure Emacs to load the package and add the specific documentation.

```lisp
(use-package info
  :config
  (add-to-list 'Info-directory-list "/path/to/demo_C-h_S/doc")
)

(use-package info-lookmore
  :load-path "~/.emacs.d/custom/"
  :config
  (info-lookmore-add-doc 'symbol 'c-mode
                         '("(demo)Function Index" nil
		           "^[ \t]+-+ \\(Function\\|Macro\\): .*\\<" "\\>")))
```

## Look for documentation

Now when needed to look for the documentation of a function at point,
press `C-h S` and Emacs will display the info file at the current
function/data type index.

![](https://github.com/secomi/demo_C-h_S/tree/master/doc/screencast.gif)


### HTML preview

[https://github.com/secomi/demo_C-h_S/blob/master/doc/demo.html](https://htmlpreview.github.io/?https://github.com/secomi/demo_C-h_S/blob/master/doc/demo.html)
