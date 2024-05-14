// @ts-check

import eslint from '@eslint/js';
import tseslint from 'typescript-eslint';

import parser from '@typescript-eslint/parser';
import react from 'eslint-plugin-react';
import teslint from '@typescript-eslint/eslint-plugin';
import globals from 'globals';
import nplugin from 'eslint-plugin-n';

export default tseslint.config(
  {
    extends: [
      eslint.configs.recommended,
      ...tseslint.configs.recommendedTypeChecked,
      ...tseslint.configs.stylisticTypeChecked,
      nplugin.configs['flat/recommended'],
    ],
    plugins: {
      react,
      teslint,
    },
    languageOptions: {
      sourceType: "module",
      ecmaVersion: 2021,
      parser: parser,
      parserOptions: {
        project: true,
        ecmaFeatures: {
          jsx: true
        },
        ecmaVersion: 15,
        sourceType: "module"
      },
      globals: {
        ...globals.browser,
      }
    },
    files: ["src/**/*.ts", "src/**/*.tsx"],
    ignores: [
      "**/*.js",
      "src/vendor/**/*.ts",
      "src/vendor/**/*.js",
    ],
    rules: {
      "@typescript-eslint/no-unused-vars": "warn",
      "@typescript-eslint/no-explicit-any": "warn",
      "no-inner-declarations": "warn",
      "@typescript-eslint/no-inferrable-types": "warn",
      "@typescript-eslint/no-unsafe-argument": "warn",
      "@typescript-eslint/no-unsafe-call": "warn",
      "@typescript-eslint/no-unsafe-member-access": "warn",
      "@typescript-eslint/no-unsafe-return": "warn",
      "@typescript-eslint/no-unsafe-assignment": "warn",
      "@typescript-eslint/no-empty-function": "warn",
      "@typescript-eslint/consistent-type-definitions": "warn",
      "@typescript-eslint/restrict-template-expressions": "warn",
      "@typescript-eslint/prefer-optional-chain": "warn",
      "@typescript-eslint/require-await": "warn",
      "@typescript-eslint/no-misused-promises": "off",
      'react/jsx-uses-react': 'error',
      'react/jsx-uses-vars': 'error',
      "n/no-missing-import": 'off'
    }
  }
);