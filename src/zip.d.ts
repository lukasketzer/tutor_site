// ponytail: vite handles .zip via assetsInclude, this just tells svelte-check the URL type
declare module '*.zip' {
	const src: string;
	export default src;
}
