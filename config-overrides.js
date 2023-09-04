// https://docs.immutable.com/docs/x/create-react-app-webpack-5-errors/
// https://stackoverflow.com/questions/64557638/how-to-polyfill-node-core-modules-in-webpack-5
const webpack = require('webpack');
module.exports = function override(config) {
  const fallback = config.resolve.fallback || {};
  Object.assign(fallback, {
    crypto: require.resolve('crypto-browserify'),
    stream: require.resolve('stream-browserify'),
    assert: require.resolve('assert'),
    http: require.resolve('stream-http'),
    https: require.resolve('https-browserify'),
    os: require.resolve('os-browserify'),
    url: require.resolve('url'),
    path: require.resolve('path-browserify')
  });
  config.resolve.fallback = fallback;
  config.plugins = (config.plugins || []).concat([
    new webpack.ProvidePlugin({
      process: 'process/browser',
      Buffer: ['buffer', 'Buffer'],
    }),
  ]);
  config.module.rules.push({
    test: /\.m?js/,
    resolve: {
      fullySpecified: false,
    },
  });
  // https://github.com/react-bootstrap-table/react-bootstrap-table2/pull/1506
  config.resolve = {
    ...config.resolve,
    alias: {
      ...config.resolve.alias,
      'react-bootstrap-table2-toolkit-css': `react-bootstrap-table2-toolkit/dist/react-bootstrap-table2-toolkit.min.css`,
      'react-bootstrap-table2-toolkit': `react-bootstrap-table2-toolkit/dist/react-bootstrap-table2-toolkit.js`,
    }
  }
  return config;
};