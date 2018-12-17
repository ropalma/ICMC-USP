# OSS Project Generator

[![Travis Status][travis-badge]][travis-url]
[![AppVeyor Status][appveyor-badge]][appveyor-url]
[![CircleCI Status][circleci-badge]][circleci-url]
[![Coveralls Status][coveralls-badge]][coveralls-url]
[![NPM Version][npm-badge]][npm-url]
[![License][license-badge]][license-url]

> Yeoman generator for open source projects.

This generator provides the following features:

* **src** and **test** folder as a starter point to build your project.
* **EditorConfig** to help you define and maintain consistent coding styles between different editors.
* **ESLint** to provide a pluggable linting utility for JavaScript.
* **Jest** as a complete and easy to set-up JavaScript testing solution used by Facebook.
* **Travis** and **CircleCI** as a continuous integration and delivery platform.
* **Appveyor** as a continuous delivery service for Windows.
* **Coveralls** to help you track your code coverage over time, and ensure that all your new code is fully covered.
* **README.md** and **CHANGELOG.md** with information about the project, installation, usage, development, author and license.
* **Badges** for Travis, Appveyor, CircleCI, Coveralls, NPM and License.

## Project files

```text
.
|--- src
|    |--- index.js
|--- test
|    |--- test.js
|--- .editorconfig
|--- .eslintignore
|--- .eslintrc
|--- .gitattributes
|--- .gitignore
|--- .npmrc
|--- .travis.yml
|--- appveyor.yml
|--- CHANGELOG.md
|--- circle.yml
|--- LICENSE
|--- package.json
|--- README.md
```

## Installation

* Install Yeoman

```bash
$ npm install -g yo
```

* Install Generator

```bash
$ npm install -g generator-oss-project
```

## Usage

* Creating a project

```bash
# Create a directory for your project
$ mkdir awesome-project

# Change into directory
$ cd awesome-project

# Generate a project
$ yo oss-project
```

* Running project

Action | Usage
---    | ---
Starting development mode                | `npm start`
Linting code                             | `npm run lint`
Running unit tests                       | `npm run jest`
Running code coverage                    | `npm run coverage`
Running lint + tests                     | `npm test`
Sending coverage results to Coveralls.io | `npm run coveralls`

## Development

### Prerequisites

* Install [Node.js](https://nodejs.org)
* Install [npm](https://www.npmjs.com/)
* Install Yeoman CLI

```bash
$ npm install -g yo
```

### Clone the repo

```bash
$ git clone https://github.com/robertoachar/generator-oss-project.git
```

### Run generator

```bash
# Change into directory
$ cd generator-oss-project

# Link generator
$ npm link

# Run generator
$ yo oss-project
```

## Author
[Roberto Achar](https://twitter.com/robertoachar)

## License
[MIT](https://github.com/robertoachar/generator-oss-project/blob/master/LICENSE)

[travis-badge]: https://travis-ci.org/robertoachar/generator-oss-project.svg?branch=master
[travis-url]: https://travis-ci.org/robertoachar/generator-oss-project

[appveyor-badge]: https://ci.appveyor.com/api/projects/status/github/robertoachar/generator-oss-project?branch=master&svg=true
[appveyor-url]: https://ci.appveyor.com/project/robertoachar/generator-oss-project

[circleci-badge]: https://circleci.com/gh/robertoachar/generator-oss-project/tree/master.svg?style=shield
[circleci-url]: https://circleci.com/gh/robertoachar/generator-oss-project

[coveralls-badge]: https://coveralls.io/repos/github/robertoachar/generator-oss-project/badge.svg?branch=master
[coveralls-url]: https://coveralls.io/github/robertoachar/generator-oss-project?branch=master

[npm-badge]: https://img.shields.io/npm/v/generator-oss-project.svg
[npm-url]: https://www.npmjs.com/package/generator-oss-project

[license-badge]: https://img.shields.io/github/license/robertoachar/generator-oss-project.svg
[license-url]: https://opensource.org/licenses/MIT
